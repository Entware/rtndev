#
# Copyright (C) 2011-2024 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bochs
PKG_VERSION:=2.8
PKG_REV:=9177c93e4e69a5c9408a1393766f882ed1313ab3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/bochs-emu/Bochs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=bd7971875af3bd0b374e303a6b3bc2d1e35c97fa695d89d85e3aefa0e97519b9

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bochs
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libncurses +libstdcpp
	TITLE:=x86 PC emulator
	URL:=http://bochs.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/bochs/description
 Bochs is a highly portable open source IA-32 (x86) PC emulator written in C++,
 that runs on most popular platforms. It includes emulation of the Intel x86 CPU,
 common I/O devices, and a custom BIOS.
endef

CONFIGURE_PATH:=bochs
MAKE_PATH:=$(CONFIGURE_PATH)

CONFIGURE_ARGS += \
	--without-x11 \
	--disable-readline \
	--with-nogui \
	--with-rfb \
	--with-term \
	--disable-disasm \
	--disable-docbook \
	--enable-ne2000 \
	--enable-pnic \
	--enable-e1000

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include

TARGET_LDFLAGS += \
	-lncurses \
	-lpthread

define Package/bochs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{bochs,bximage} \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/bochs \
		$(1)/opt/share
endef

$(eval $(call BuildPackage,bochs))
