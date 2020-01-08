#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bochs
PKG_VERSION:=2.6.11
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=63897b41fbbbdfb1c492d3c4dee1edb4224282a07bbdf442a4a68c19bcc18862

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
