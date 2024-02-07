# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2020-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=zbar
PKG_VERSION:=0.23.93
PKG_REV:=bb05ec54eec57f8397cb13fb9161372a281a1219
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/mchehab/zbar
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f678cf14b03b49a5fa395c18916fdc9e7c0c92a335a9387d10dff19a2ec9bc1c

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

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

CONFIGURE_ARGS += \
	--disable-doc \
	--disable-video \
	--with-graphicsmagick \
	--without-gtk \
	--without-imagemagick \
	--without-java \
	--without-python \
	--without-qt \
	--without-qt5 \
	--without-dbus

define Package/zbar/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/zbarimg $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libzbar.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,zbar))
