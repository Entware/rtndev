#
# Copyright (C) 2011-2019 Entware
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
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mp709/description
 mp709 - a lightweight tool for monipulating MP709 USB relay from masterkit.ru
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include -c \
	$(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -lusb-1.0 \
	-o $(PKG_BUILD_DIR)/mp709 $(PKG_BUILD_DIR)/mp709m.c
endef

define Package/mp709/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mp709 $(1)/opt/bin
endef

$(eval $(call BuildPackage,mp709))
