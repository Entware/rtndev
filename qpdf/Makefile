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
PKG_VERSION:=11.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/qpdf/qpdf/releases/download/v$(PKG_VERSION)
PKG_HASH:=b0180971cc1b79b2dfe02ffe28e2c88c47f735888a3a2543dd42b9054ef146e1

CMAKE_INSTALL:=1

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

CMAKE_BINARY_SUBDIR:=build

TARGET_LDFLAGS += -latomic

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

$(eval $(call BuildPackage,qpdf))
