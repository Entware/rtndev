#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mp709
PKG_RELEASE:=2

include $(INCLUDE_DIR)/package.mk

define Package/mp709
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libusb-1.0
	TITLE:=a tool for monipulating MP709 USB relay
	URL:=http://wl500g.info/showthread.php?20497&p=257339#post257339
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/mp709/description
 mp709 - a lightweight tool for monipulating MP709 USB relay from masterkit.ru
endef

define Build/Prepare
	$(INSTALL_DIR) $(PKG_BUILD_DIR)
	$(INSTALL_DATA) ./src/$(PKG_NAME)m.c $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(STAGING_DIR)/opt/include -o $(PKG_BUILD_DIR)/$(PKG_NAME).o $(PKG_BUILD_DIR)/$(PKG_NAME)m.c
	$(TARGET_CC) $(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -o $(PKG_BUILD_DIR)/$(PKG_NAME) $(PKG_BUILD_DIR)/$(PKG_NAME).o -lusb-1.0
endef

define Package/mp709/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mp709 $(1)/opt/bin
endef

$(eval $(call BuildPackage,mp709))
