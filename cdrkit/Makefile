# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1115

include $(TOPDIR)/rules.mk

PKG_NAME:=cdrkit
PKG_VERSION:=1.1.11
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).orig.tar.gz
PKG_SOURCE_URL:=@DEBIAN/pool/main/c/cdrkit
PKG_HASH:=d1c030756ecc182defee9fe885638c1785d35a2c2a297b4604c0e0dcc78e47da

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

PKG_UNPACK += --strip-components=1 -C $(PKG_BUILD_DIR)

define Package/cdrkit
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=a suite of programs for recording CDs/DVDs and more
  URL:=http://andre-simon.de/
  DEPENDS:=+libbz2 +libcap +libmagic +zlib
  # dirsplit deps
  DEPENDS+=+perlbase-base +perlbase-file +perlbase-getopt +perlbase-list
endef

define Package/cdrkit/description
  cdrkit is a suite of programs for recording CDs and DVDs, blanking
 CD-RW media, creating ISO-9660 filesystem images, extracting audio CD data, and
 more.
endef

define Package/cdrkit/conffiles
/opt/etc/netscsid.conf
/opt/etc/wodim.conf
endef

ifeq ($(CONFIG_BIG_ENDIAN),y)
  CMAKE_OPTIONS += \
	-DBITFIELDS_HTOL=1
else
  CMAKE_OPTIONS += \
	-DBITFIELDS_HTOL=0
endif

CMAKE_OPTIONS += \
	-DUSE_LIBC_NLS=ON \
	-DUSE_LIBXNET=OFF \
	-DUSE_LIBNLS=OFF \
	-DUSE_MAGIC=ON

define Package/cdrkit/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cdda2ogg $(1)/opt/bin
	$(LN) cdda2ogg $(1)/opt/bin/cdda2mp3
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/devdump $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/dirsplit $(1)/opt/bin
	$(SED) 's,^#!.*perl,#!/opt/bin/perl,' $(1)/opt/bin/dirsplit
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/genisoimage $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/icedax $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/iso{debug,dump,info,vfy} \
		$(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/pitchplay $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/readmult $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/readom $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/wodim $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/netscsid $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/netscsid/netscsid.dfl \
		 $(1)/opt/etc/netscsid.conf
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/wodim/wodim.dfl $(1)/opt/etc/wodim.conf
endef

$(eval $(call BuildPackage,cdrkit))
