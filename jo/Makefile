#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jo
PKG_VERSION:=1.6
PKG_REV:=6962bca178a6778328d1126ff762120305bb4327
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jpmens/jo.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=0a9d444f3d07950dd19857766ac651383b93825fe7f1c99bc0b4348e98841b47

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
