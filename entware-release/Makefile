# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=entware-release
PKG_VERSION:=2024.07
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/kernel.mk

define Package/entware-release
	SECTION:=base
	CATEGORY:=Base system
	TITLE:=Entware release information
	MAINTAINER:=Entware team, https://entware.net
	PKGARCH:=all
endef

define Package/entware-release/description
 entware_release is a file in /opt/etc with entware info.
endef

ifneq ($(firstword "x$(CONFIG_CPU_TYPE)"), "x")
CPUTYPE=$(CONFIG_CPU_TYPE)
else
CPUTYPE=unknown
endif
CPUSUBTYPE=$(if $(CONFIG_CPU_SUBTYPE),$(CONFIG_CPU_SUBTYPE),unknown)
FLOAT=$(if $(CONFIG_SOFT_FLOAT),soft,hard)

ENVCFLAGS:=$(TARGET_OPTIMIZATION) $(call qstrip,$(CONFIG_EXTRA_OPTIMIZATION))
ifeq ($(CONFIG_SOFT_FLOAT),y)
    ifeq ($(CONFIG_arm),y)
        ENVCFLAGS+= -mfloat-abi=soft
    else
        ENVCFLAGS+= -msoft-float
    endif
endif

# skip steps
Build/Prepare:=:
Build/Configure:=:
Build/Compile:=:

define Package/entware-release/install
	$(INSTALL_DIR) $(1)/opt/etc
	echo "PRETTY_NAME=\"Entware $(PKG_VERSION)\"" > $(1)/opt/etc/entware_release
	echo "NAME=\"Entware\"" >> $(1)/opt/etc/entware_release
	echo "VERSION_ID=\"$(PKG_VERSION)\"" >> $(1)/opt/etc/entware_release
	echo "VERSION=\"$(PKG_VERSION) (sync with OpenWrt)\"" >> $(1)/opt/etc/entware_release
	echo "ID=entware" >> $(1)/opt/etc/entware_release
	echo "HOME_URL=\"https://entware.net/\"" >> $(1)/opt/etc/entware_release
	echo "SUPPORT_URL=\"https://github.com/Entware/Entware/discussions/\"" >> $(1)/opt/etc/entware_release
	echo "BUG_REPORT_URL=\"https://github.com/Entware/Entware/issues/\"" >> $(1)/opt/etc/entware_release
	echo "" >> $(1)/opt/etc/entware_release
	echo "Build summary:" >> $(1)/opt/etc/entware_release
	echo "Linux Kernel $(LINUX_VERSION)" >> $(1)/opt/etc/entware_release
	echo "arch=$(ARCH)" >> $(1)/opt/etc/entware_release
	echo "cpu_type=$(CPUTYPE)" >> $(1)/opt/etc/entware_release
	echo "cpu_subtype=$(CPUSUBTYPE)" >> $(1)/opt/etc/entware_release
	echo "float=$(FLOAT)" >> $(1)/opt/etc/entware_release
	echo "binutils_version=\"$(call qstrip,$(CONFIG_BINUTILS_VERSION))\"" >> $(1)/opt/etc/entware_release
	echo "gcc_version=\"$(call qstrip,$(CONFIG_GCC_VERSION))\"" >> $(1)/opt/etc/entware_release
	echo "gcc_flags=\"$(ENVCFLAGS)\"" >> $(1)/opt/etc/entware_release
	echo "libc_type=glibc" >> $(1)/opt/etc/entware_release
	echo "libc_version=\"$(call qstrip,$(CONFIG_GLIBC_VERSION))\"" >> $(1)/opt/etc/entware_release
endef

$(eval $(call BuildPackage,entware-release))
