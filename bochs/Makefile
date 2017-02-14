#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bochs
PKG_VERSION:=2.6.8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_VERSION)
PKG_MDSUM:=8a243e2b5f7562f32d2b26f3cebbba08

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bochs
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libpthread +libstdcpp
	TITLE:=x86 PC emulator
	URL:=http://bochs.sourceforge.net/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/bochs/description
 Bochs is a highly portable open source IA-32 (x86) PC emulator written in C++,
 that runs on most popular platforms. It includes emulation of the Intel x86 CPU,
 common I/O devices, and a custom BIOS.
endef

CONFIGURE_ARGS += \
	--enable-cpu-level=5 \
	--enable-ne2000 \
	--disable-readline \
	--disable-disasm \
	--disable-docbook \
	--without-x11 \
	--with-rfb \
	--with-nogui

TARGET_LDFLAGS += \
	-lpthread

define Package/bochs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{bochs,bximage} \
		$(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/share/bochs
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/bochs/{BIOS,VGABIOS}-* \
		$(1)/opt/share/bochs
endef

$(eval $(call BuildPackage,bochs))
