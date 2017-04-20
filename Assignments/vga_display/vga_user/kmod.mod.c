#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xd5e2f3fe, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5d41c87c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x648f47f5, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xa356c774, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x8c2d2e9b, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xe4334e72, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xc942a98b, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x1a0d05dc, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xbaece9f2, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x8c613376, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xb0783f51, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "8C7286FCA69A7ACC1C9F147");
