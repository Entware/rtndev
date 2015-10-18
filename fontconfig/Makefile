#
# Copyright (C) 2011-2015 Entware
# Copyright (C) 2013 Francisco Borges
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=fontconfig
PKG_VERSION:=2.11.94
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://fontconfig.org/release/
PKG_MD5SUM:=c988ea12f4117330246e041109152b4a

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/fontconfig
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+libfreetype +libexpat +libpthread
	TITLE:=Fontconfig, configure and customize font access
	URL:=http://fontconfig.org
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/fontconfig/description
 The Fontconfig package contains a library and support programs used for
 configuring and customizing font access.
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include/freetype2

CONFIGURE_ARGS += \
	--disable-docs

define Package/fontconfig/install
	$(INSTALL_DIR) $(1)/opt/etc/fonts/conf.d $(1)/opt/var/cache/fontconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/fonts/fonts.conf $(1)/opt/etc/fonts
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/fonts/conf.d/* $(1)/opt/etc/fonts/conf.d
	$(INSTALL_DIR) $(1)/opt/{bin,lib}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/fc-* $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libfontconfig.so* $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/share/fontconfig/conf.avail
	$(CP) $(PKG_INSTALL_DIR)/opt/share/fontconfig/conf.avail/* $(1)/opt/share/fontconfig/conf.avail
endef

define Package/fontconfig/postinst
#!/bin/sh
/opt/bin/fc-cache --force --verbose
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include/fontconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/include/fontconfig/*.h $(1)/opt/include/fontconfig/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/* $(1)/opt/lib
endef

$(eval $(call BuildPackage,fontconfig))
