# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=entr
PKG_VERSION:=5.5
PKG_REV:=8ed69ace080a73ff923c20f01a3ded28df3b4e1c
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/eradman/entr.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=eb2dd0f11573a69c18a7d9dd2814a1f9da6f59337f0859e51fc0a69dab40cb13

include $(INCLUDE_DIR)/package.mk

define Package/entr
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=run arbitrary commands when files change
	URL:=http://eradman.com/entrproject/
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
