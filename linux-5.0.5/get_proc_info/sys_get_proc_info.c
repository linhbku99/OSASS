#include <linux/kernel.h>
#include <linux/syscalls.h>

struct proc_info {
        pid_t pid;
        char name[16];
};
struct procinfos {
	long studentID;
	struct proc_info proc;
	struct proc_info parent_proc;
	struct proc_info oldest_child_proc;
};

//asmlinkage long sys_get_proc_info(pid_t pid, struct procinfos * info){
SYSCALL_DEFINE2(get_proc_info, pid_t, pid, struct procinfos *, info){
	printk("studenID: 1710188");
	info->studentID = 1710188;

	struct task_struct *ts;

	if(pid == -1) pid = current->pid;

	for_each_process(ts){
		if(ts->pid==pid){
			struct task_struct *ctask;

			ctask = list_first_entry_or_null(&ts->children, struct task_struct, sibling);

			//current or founded
			info->proc.pid = ts->pid;
			strcpy(info->proc.name,ts->comm);

			//parent
			if (ts->real_parent != NULL) {

				info->parent_proc.pid = ts->real_parent->pid;
				strcpy(info->parent_proc.name,ts->real_parent->comm);
			} else {

				info->parent_proc.pid = 0;
				info->parent_proc.name = "\0";
			}

			//oldest child
			if (ctask != NULL) {
				info->oldest_child_proc.pid = ctask->pid;
				strcpy(info->oldest_child_proc.name,ctask->comm);
			} else {

				info->oldest_child_proc.pid = 0;
				info->oldest_child_proc.name = "\0";
			}
			return 0;
		}
	}
	return EINVAL;
}
