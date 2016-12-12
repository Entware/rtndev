#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=goaccess
PKG_VERSION:=1.1.1-20161206
PKG_REV:=316c9b30d47ca5ef329c58c41dc035a722257575
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/allinurl/goaccess.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/goaccess
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=web log analyzer
	DEPENDS:=+libncursesw +libpthread
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
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
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/goaccess.conf $(1)/opt/etc
endef

define Package/goaccess/conffiles
/opt/etc/goaccess.conf
endef

$(eval $(call BuildPackage,goaccess))
