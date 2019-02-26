#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=goaccess
PKG_VERSION:=1.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://tar.goaccess.io
PKG_HASH:=8c775c5c24bf85a933fd6f1249004847342d6542aa533e4ec02aaf7be41d7b9b

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/goaccess
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=web log analyzer
	DEPENDS:=+libncursesw +libpthread
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/goaccess/description
 GoAccess is a real-time web log analyzer and interactive viewer that runs
 in a terminal in *nix systems or through your browser.
endef

CONFIGURE_ARGS += \
	--enable-utf8

define Build/Compile
	$(HOSTCC) -o $(PKG_BUILD_DIR)/bin2c $(PKG_BUILD_DIR)/src/bin2c.c
	$(call Build/Compile/Default)
endef

define Package/goaccess/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/goaccess $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/goaccess
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/goaccess/{browsers.list,goaccess.conf} \
	    $(1)/opt/etc/goaccess
endef

define Package/goaccess/conffiles
/opt/etc/goaccess/goaccess.conf
endef

$(eval $(call BuildPackage,goaccess))
