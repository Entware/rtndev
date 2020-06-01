#
# Copyright (C) 2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# 0.23.1 unconditionally uses NLS and translations. Sure it will be fixed in the next version

include $(TOPDIR)/rules.mk

PKG_NAME:=zbar
PKG_VERSION:=0.23
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_REV:=1d51925e6cc9151f4a73781989f21fcd7b57ef32
PKG_SOURCE_URL:=https://github.com/mchehab/zbar
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

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
