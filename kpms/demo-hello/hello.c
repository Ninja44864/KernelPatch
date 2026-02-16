#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <kpmodule.h>

// This runs as the kernel initializes
static int __init prod_off_init(void) {
    // Look up the command line in kernel memory
    char *cmdline = (char *)kallsyms_lookup_name("saved_command_line");
    
    if (cmdline) {
        // Find and flip the secure_hardware flag
        char *sec_hw = strstr(cmdline, "androidboot.secure_hardware=1");
        if (sec_hw) {
            sec_hw[28] = '0'; 
        }
        
        // Find and flip the production flag
        char *prod = strstr(cmdline, "ro.product.is_production=true");
        if (prod) {
            // We use memcpy to change 'true' to 'fals' (keeping it same length is safer)
            memcpy(prod + 25, "fals", 4);
        }
    }
    return 0;
}

static void __exit prod_off_exit(void) {
}

module_init(prod_off_init);
module_exit(prod_off_exit);
MODULE_LICENSE("GPL");
