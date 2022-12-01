#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=qpdf
PKG_VERSION:=11.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/qpdf/qpdf/releases/download/v$(PKG_VERSION)
PKG_HASH:=fbd2d75050933487929dbbe1b5c50a238487194bc7263c277d6e49abb90ab7f2

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/qpdf
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libjpeg +libgnutls +zlib +libstdcpp
	TITLE:=PDF transformations utility
	URL:=http://qpdf.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/qpdf/description
 QPDF is a command-line program for transformations on PDF files.
endef

CMAKE_OPTIONS += \
	-DUSE_IMPLICIT_CRYPTO=0 \
	-DREQUIRE_CRYPTO_GNUTLS=1 \
	-DRANDOM_DEVICE=/dev/urandom

define Package/qpdf/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libqpdf.so* $(1)/opt/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/qpdf $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libqpdf.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libqpdf.pc $(1)/opt/lib/pkgconfig
endef

$(eval $(call BuildPackage,qpdf))
