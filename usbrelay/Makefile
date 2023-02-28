#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=usbrelay
PKG_VERSION:=1.1.2
PKG_REV:=9fb5f0003f9592f97f1a2d59208b52d018f4c908
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/darrylb123/usbrelay.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=d150d327d5da4d5ab6821c340c4f518bae19bd3e0a405b12aec18fe8fb9eaa61

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/usbrelay
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+hidapi
	TITLE:=control usb relay
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/usbrelay/description
 USB Relay driver for linux.
endef

define Package/usbrelay/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/libusbrelay.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,usbrelay))
