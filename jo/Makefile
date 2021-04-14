#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jo
PKG_VERSION:=1.4
PKG_REV:=dd9c49e32f36ebbfa341d2e23b540e40bcd418a8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jpmens/jo.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=97d241b5a9be856b75a99536458405a6fb7d8b4fcc856f0696d0102c061a542d

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
