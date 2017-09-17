#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rtl_433
PKG_VERSION:=0.1-20170827
PKG_REV:=c6e79a33bd443d271b8d35ccd29d32e709ff9382
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/merbanan/rtl_433.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/rtl_433
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=getting temperature from a wireless sensors
	DEPENDS:=rtl-sdr
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/rtl_433/description
 Application using librtlsdr to decode the temperature from a wireless
 temperature sensor (433.92MHz)
endef

define Package/rtl_433/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/rtl_433 $(1)/opt/bin
endef

$(eval $(call BuildPackage,rtl_433))
