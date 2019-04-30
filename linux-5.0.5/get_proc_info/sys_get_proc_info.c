#include <linux/kernel.h>
#include <unistd.h>
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
//asmlinkage long sys_get_proc_info(pid_t pid, struct procinfos *info)
SYSCALL_DEFINE2(get_proc_info, pid_t, pid, struct procinfos *, info)
{
	info->studenID = 1710165;
	printk("Student ID: %ld\n", info->studenID);
	if (pid == -1) {
		pid = current->pid;
	}
	struct tash_struct *proces;
	for_each_process (proces) {
		if (proces->pid == pid) {
			struct task_struct *cProces;
			cProces = list_first_entry_or_null(
				&proces->children, struct task_struct, sibling);
			info->proc.pid = proces->pid;
			strcpy(info->proc.name, proces->comm);
			if (proces->real_parent == NULL) {
				info->parent_proc.pid = 0;
				info->parent_proc.name = "\0";
			} else {
				info->parent_proc.pid =
					proces->real_parent->pid;
				info->patent_proc.name =
					proces->real_parent->comm;
			}
			if (cProces == NULL) {
				info->oldest_child_proc.pid = 0;
				info->oldest_child_proc.name = "\0";
			} else {
				info->oldest_child_proc.pid = cProces->pid;
				info->oldest_child_proc.name = cProces->comm;
			}
		}
	}
	return EINVAL;
}
