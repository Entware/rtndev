#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=usbrelay
PKG_VERSION:=0.8
PKG_REV:=d150f878b3e43bb9a944f916faafc2fe9ef3b3c2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/darrylb123/usbrelay.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=34e6f711acf18ff7bc3acb0a616beb414d061cbc0fd33c866d4aef89e6cdad86

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/usbrelay
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+hidapi $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=control usb relay
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/usbrelay/description
 USB Relay driver for linux.
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include \
		-o $(PKG_BUILD_DIR)/$(PKG_NAME) \
		$(PKG_BUILD_DIR)/usbrelay.c $(PKG_BUILD_DIR)/libusbrelay.c \
		$(TARGET_LDFLAGS) -lhidapi-libusb
endef

define Package/usbrelay/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/opt/bin
endef

$(eval $(call BuildPackage,usbrelay))
