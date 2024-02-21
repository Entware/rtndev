# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#
# 1.9.0-1.9.1 uses _sync_add_and_fetch() which is unportable to mips

include $(TOPDIR)/rules.mk

PKG_NAME:=goaccess
PKG_VERSION:=1.8.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://tar.goaccess.io
PKG_HASH:=7f9432e6e95d0ece40be86d33f3c454b9c5eec31766914bc9c12f9cf4ead4597

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/goaccess
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=web log analyzer
	DEPENDS:=+libncursesw
	URL:=https://goaccess.io/
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
	    $(PKG_INSTALL_DIR)/opt/etc/goaccess/{browsers.list,goaccess.conf,podcast.list} \
	    $(1)/opt/etc/goaccess
endef

define Package/goaccess/conffiles
/opt/etc/goaccess/goaccess.conf
endef

$(eval $(call BuildPackage,goaccess))
