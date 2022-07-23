#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=usbrelay
PKG_VERSION:=1.0
PKG_REV:=b3023dca3845e6f4701c32b4b043eae05c70ca96
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/darrylb123/usbrelay.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4ed6f3ac592f08c5458f64f97f4a1e6711b175fcad3663a0c041c9152f127fe3

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
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libusbrelay.so $(1)/opt/lib
endef

$(eval $(call BuildPackage,usbrelay))
