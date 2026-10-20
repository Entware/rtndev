# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=entr
PKG_VERSION:=5.9
PKG_REV:=af3a7093d5e8eea2886d988f266fbc229781ef75
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/eradman/entr.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=5854fd96485980000ff02e87522ba693ef700cbd8f362192954e2c1a4ebf5706

include $(INCLUDE_DIR)/package.mk

define Package/entr
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=run arbitrary commands when files change
	URL:=https://eradman.com/entrproject/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/entr/description
 A utility for running arbitrary commands when files change.
endef

define Build/Configure
	$(LN) $(PKG_BUILD_DIR)/Makefile.linux $(PKG_BUILD_DIR)/Makefile
endef

define Package/entr/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/entr $(1)/opt/bin
endef

$(eval $(call BuildPackage,entr))
