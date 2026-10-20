# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2020-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=zbar
PKG_VERSION:=0.23.95
PKG_REV:=dc19fcc7da58e8cf84ba1ec417e24b04609feb23
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/mchehab/zbar
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=2881e059c3765ac462bb8eb01cf0e64a3e07f7fe123d29389092307dd4bac855

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

define Package/zbar
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+graphicsmagick
	TITLE:=bar code scanning and decoding
	URL:=https://github.com/mchehab/zbar
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/zbar/description
 ZBar Bar Code Reader is an open source software suite for reading bar codes
 from various sources, such as video streams, image files and raw intensity
 sensors. It supports EAN-13/UPC-A, UPC-E, EAN-8, Code 128, Code 93, Code 39,
 Codabar, Interleaved 2 of 5, QR Code and SQ Code.
endef

MESON_ARGS += \
	-Dbuild_tests=false \
	-Ddbus=disabled \
	-Ddoc=false \
	-Dgir=false \
	-Dgraphicsmagick=enabled \
	-Dgtk=no \
	-Dimagemagick=auto \
	-Djava=disabled \
	-Dlibrary_type=shared \
	-Dnls=disabled \
	-Dpython=no \
	-Dqt=false \
	-Dvideo=false \
	-Dx11=disabled

define Package/zbar/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/zbarimg $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libzbar.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,zbar))
