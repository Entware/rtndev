# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2013 Francisco Borges https://github.com/FranciscoBorges/openwrt-printing-packages
# Copyright (C) 2011-2026 Entware
#
# 12.3.0 requires c++20 <concept>

include $(TOPDIR)/rules.mk

PKG_NAME:=qpdf
PKG_VERSION:=12.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/qpdf/qpdf/releases/download/v$(PKG_VERSION)
PKG_HASH:=b3d1575b2218badc3549d6977524bb0f8c468c6528eebc8967bbe3078cf2cace

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
