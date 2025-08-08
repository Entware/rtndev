# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/994 (as deps)

include $(TOPDIR)/rules.mk

PKG_NAME:=kronosnet
PKG_VERSION:=1.31
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://kronosnet.org/releases
PKG_HASH:=dd4effc86cfb4590007a6fcb3ea245512d684056399fa1bafa5d58208b17f953

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-or-later LGPL-2.1-or-later
PKG_LICENSE_FILES:=COPYING.applications COPYING.libraries COPYRIGHT

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_CONFIG_DEPENDS:= \
	CONFIG_KRONOSNET_COMPRESS_BZIP2 \
	CONFIG_KRONOSNET_COMPRESS_LZ4 \
	CONFIG_KRONOSNET_COMPRESS_LZMA \
	CONFIG_KRONOSNET_COMPRESS_LZO2 \
	CONFIG_KRONOSNET_COMPRESS_ZLIB \
	CONFIG_KRONOSNET_COMPRESS_ZSTD \
	CONFIG_KRONOSNET_CRIPTO_NSS \
	CONFIG_KRONOSNET_CRIPTO_OPENSSL \
	CONFIG_KRONOSNET_INSTALL_TESTS

PKG_BUILD_DEPENDS:=libnl libqb openssl zlib

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libknet
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Kronosnet core switching implementation
  URL:=https://kronosnet.org
  DEPENDS:= \
	+KRONOSNET_COMPRESS_BZIP2:libbz2 \
	+KRONOSNET_COMPRESS_LZ4:liblz4 \
	+KRONOSNET_COMPRESS_LZMA:liblzma \
	+KRONOSNET_COMPRESS_LZO2:liblzo \
	+KRONOSNET_COMPRESS_ZLIB:zlib \
	+KRONOSNET_COMPRESS_ZSTD:libzstd \
	+KRONOSNET_CRIPTO_NSS:libnss \
	+KRONOSNET_CRIPTO_OPENSSL:libopenssl \
	+KRONOSNET_INSTALL_TESTS:libnozzle
  MENU:=1
endef

define Package/libknet/description
  The whole kronosnet core is implemented in this library.
  Please refer to the not-yet-existing documentation for further information.
endef

define Package/libnozzle
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Simple userland wrapper around kernel tap devices
  URL:=https://kronosnet.org
  DEPENDS:=+libnl-route
endef

define Package/libnozzle/description
  This is an over-engineered commodity library to manage a pool of tap
 devices and provides the basic pre-up.d/up.d/down.d/post-down.d infrastructure.
endef

define Package/libknet/config
  source "$(SOURCE)/Config.in"
endef

CONFIGURE_ARGS += \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_BZIP2),en,dis)able-compress-bzip2 \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_LZ4),en,dis)able-compress-lz4 \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_LZMA),en,dis)able-compress-lzma \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_LZO2),en,dis)able-compress-lzo2 \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_ZLIB),en,dis)able-compress-zlib \
	--$(if $(CONFIG_KRONOSNET_COMPRESS_ZSTD),en,dis)able-compress-zstd \
	--$(if $(CONFIG_KRONOSNET_CRIPTO_NSS),en,dis)able-crypto-nss \
	--$(if $(CONFIG_KRONOSNET_CRIPTO_OPENSSL),en,dis)able-crypto-openssl \
	--$(if $(CONFIG_KRONOSNET_INSTALL_TESTS),en,dis)able-install-tests \
	--disable-functional-tests \
	--disable-libknet-sctp \
	--disable-man

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/*.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.{a,so*} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/*.pc $(1)/opt/lib/pkgconfig
endef

define Package/libknet/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libknet.so* $(1)/opt/lib
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_BZIP2),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_bzip2.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_LZ4),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_lz4.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_LZMA),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_lzma.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_LZO2),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_lzo2.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_ZLIB),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_zlib.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_COMPRESS_ZSTD),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/compress_zstd.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_CRIPTO_NSS),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/crypto_nss.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_CRIPTO_OPENSSL),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/crypto_openssl.so \
		$(1)/opt/lib/kronosnet
  endif
  ifeq ($(CONFIG_KRONOSNET_INSTALL_TESTS),y)
	$(INSTALL_DIR) $(1)/opt/lib/kronosnet/tests
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/kronosnet/tests/* \
		$(1)/opt/lib/kronosnet/tests
  endif
endef

define Package/libnozzle/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libnozzle.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libknet))
$(eval $(call BuildPackage,libnozzle))
