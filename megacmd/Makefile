#
# Copyright (C) 2011-2024 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=megacmd
PKG_VERSION:=1.7.0
PKG_REV:=bc0e4016eeb561677e8078294422e9b1619515b5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/meganz/MEGAcmd.git
PKG_SOURCE_PROTO:=git
PKG_MIRROR_HASH:=8b47296930c42a61ade9ca6e5e06ce26e9e6189a6d604c1292c2d299f26e6911

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/megacmd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+icu +libcares +libcryptopp +libcurl +libmediainfo \
	    +libpcre +libreadline +libsodium +libsqlite3 +libuv
	TITLE:=Command Line Interactive and Scriptable Application
	URL:=https://github.com/meganz/megacmd
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/megacmd/description
 MEGAcmd provides non UI access to MEGA services. It intends to offer all the
 functionality with your MEGA account via commands.
endef

CONFIGURE_ARGS += \
    --disable-doxygen-doc \
    --without-freeimage \
    --without-ffmpeg

define Package/megacmd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mega-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib
	$(SED) 's,^#!.*bash,#!/opt/bin/sh,' $(1)/opt/bin/*
endef

$(eval $(call BuildPackage,megacmd))
