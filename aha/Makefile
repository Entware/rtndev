#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=aha
PKG_VERSION:=0.5
PKG_REV:=5d2aa8748c5f15a0a7d22f5abc74c9777f14c7b6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/theZiz/aha.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/aha
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Ansi HTML Adapter
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/aha/description
 Converts ANSI escape sequences of a unix terminal to HTML code.
endef

define Package/aha/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/aha $(1)/opt/bin
endef

$(eval $(call BuildPackage,aha))
