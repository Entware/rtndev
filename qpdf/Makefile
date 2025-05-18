# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2025 Entware
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
#
# The newer version is incopatible with cups-filters 1.28.17
# filter/pdftopdf/qpdf_pdftopdf_processor.cc:89:10: error: 'class QPDFObjectHandle' has no member named 'replaceOrRemoveKey'

include $(TOPDIR)/rules.mk

PKG_NAME:=qpdf
PKG_VERSION:=11.9.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/qpdf/qpdf/releases/download/v$(PKG_VERSION)
PKG_HASH:=2ba4d248f9567a27c146b9772ef5dc93bd9622317978455ffe91b259340d13d1

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
