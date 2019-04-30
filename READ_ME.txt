	# Install ubuntu 18.04
	# Run following commands:

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install kernel-package
sudo apt-get install fakeroot ncurses-dev xz-utils bc flex libelf-dev bison
sudo apt-get install openssl libssl-dev

mkdir ~/kernelbuild
cd ~/kernelbuild
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.0.5.tar.xz
tar -xvJf linux-5.0.5.tar.xz
cp /boot/config-$(uname -r) ~/kernelbuild/linux-5.0.5/.config
cd ~/kernelbuild/linux-5.0.5
make nconfig
	# Change your local version in General setup -> Local version then run
make -j9
	# TAKE A SNAPSHOT then run these command:
sudo make modules_install install
sudo reboot
cd ~/kernelbuild/linux-5.0.5
sudo make localmodconfig
	# Choose no for all options
make -j9
	# Copy linux-5.0.5 from the zip and merge with the exist one
	# Change your your studentID in /linux-5.0.5/get_proc_info/sys_get_proc_info.c then run
make -j9
	# TAKE A SNAPSHOT then run these command:
sudo make modules_install install
sudo reboot
	# Copy folder wrapper to wherever you like, move terminal to wrapper folder and run this command to check your work:
./run