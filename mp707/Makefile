#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2016

include $(TOPDIR)/rules.mk

PKG_NAME:=mp707
PKG_VERSION:=1.0.2
PKG_REV:=d0874e415be034637041e261cbcf2aed378bf917
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/bubbafix/openwrt-bm1707.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f52bfe3b6699582579759151972e112b47a293c5c53b775e8c8745e14b86e96b

include $(INCLUDE_DIR)/package.mk

define Package/mp707
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libusb-compat +libstdcpp
	TITLE:=USB thermometer MP707(BM1707) utility
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mp707/description
 This utility works with USB thermometer MP707 (BM1707).
 More information on device can be found at http://www.masterkit.ru
endef

define Build/Compile
	$(TARGET_CXX) $(TARGET_CXXFLAGS) -c -I$(STAGING_DIR)/opt/include -o $(PKG_BUILD_DIR)/$(PKG_NAME).o $(PKG_BUILD_DIR)/package/bmtemp/src/bmtemp.cpp
	$(TARGET_CXX) $(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -o $(PKG_BUILD_DIR)/bmtemp $(PKG_BUILD_DIR)/$(PKG_NAME).o -lusb
endef

define Package/mp707/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bmtemp $(1)/opt/bin
endef

$(eval $(call BuildPackage,mp707))
