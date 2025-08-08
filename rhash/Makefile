# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1126

include $(TOPDIR)/rules.mk

PKG_NAME:=rhash
PKG_VERSION:=1.4.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/rhash/RHash/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=9f6019cfeeae8ace7067ad22da4e4f857bb2cfa6c2deaa2258f55b2227ec937a

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=0BSD
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK += --strip-components=1 -C $(PKG_BUILD_DIR)

define Package/rhash
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Great utility for computing hash sums
  URL:=http://rhash.sf.net/
endef

define Package/rhash/description
  RHash (Recursive Hasher) is a console utility for calculation and
 verification of magnet links and various message digests, including CRC32,
 CRC32C, MD4, MD5, SHA1, SHA256, SHA512, SHA3, AICH, ED2K, DC++ TTH, BitTorrent
 BTIH, Tiger, GOST R 34.11-94, GOST R 34.11-2012, RIPEMD-160, HAS-160, EDON-R,
 and Whirlpool.
endef

define Package/rhash/conffiles
/opt/etc/rhashrc
endef

CONFIGURE_ARGS:= --prefix=/opt

BINS:= \
	ed2k-link edonr256-hash edonr512-hash \
	gost12-256-hash gost12-512-hash \
	has160-hash \
	magnet-link \
	sfv-hash \
	tiger-hash tth-hash \
	whirlpool-hash

define Package/rhash/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rhash $(1)/opt/bin
	for bins in $(BINS); do \
		$(LN) rhash $(1)/opt/bin/$$$$bins; \
	done
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/rhashrc $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/librhash.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,rhash))
