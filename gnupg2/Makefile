#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# based on Makefile from https://github.com/MarvAmBass/lede-gnupg2.git

include $(TOPDIR)/rules.mk

PKG_NAME:=gnupg2
PKG_VERSION:=2.2.23
PKG_RELEASE:=1

PKG_SOURCE:=gnupg-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=ftp://ftp.gnupg.org/gcrypt/gnupg
PKG_HASH:=10b55e49d78b3e49f1edb58d7541ecbdad92ddaeeb885b6f486ed23d1cd1da5c

PKG_LICENSE:=GPL-3.0
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_DIR:=$(BUILD_DIR)/gnupg-$(PKG_VERSION)
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/gnupg2
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Encryption
  DEPENDS:=+zlib +libbz2 +libncurses +libreadline +libpcsclite +libgnutls +libcurl +libassuan +libgcrypt +libgpg-error +libksba +npth +ccid +libsqlite3
  TITLE:=GNU privacy guard - a free PGP replacement (V2)
  URL:=http://www.gnupg.org/
  CONFLICTS:=gnupg
endef


define Package/gnupg2/description
 GnuPG is GNU's tool for secure communication and data storage.
 It can be used to encrypt data and to create digital signatures.
 It includes an advanced key management facility and is compliant
 with the proposed OpenPGP Internet standard as described in RFC2440.
 .
 GnuPG does not use any patented algorithms so it cannot be compatible
 with PGP2 because it uses IDEA (which is patented worldwide).
endef

TARGET_CFLAGS += $(FPIC)

define Package/gnupg2/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/gpg* $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/scdaemon $(1)/opt/lib/
endef

$(eval $(call BuildPackage,gnupg2))
