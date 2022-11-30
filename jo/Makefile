#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jo
PKG_VERSION:=1.9
PKG_REV:=2cc476178198774ad6bea89be0b9e4ed2d4bf4c5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jpmens/jo.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8f0e3b739332df6c5e8bbe07fcd4de44ea0a99bca63de2006417a5bd7b74b793

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/jo
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=JSON output from a shell
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/jo/description
 jo is a small utility to create JSON objects.
endef

define Package/jo/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/jo $(1)/opt/bin
endef

$(eval $(call BuildPackage,jo))
