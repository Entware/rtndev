# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=man-db
PKG_VERSION:=2.12.0
PKG_RELEASE:=1

PKG_SOURCE_URL:=@SAVANNAH/man-db
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_HASH:=415a6284a22764ad22ff0f66710d853be7790dd451cd71436e3d25c74d996a95

PKG_LICENSE:=GPL-2.0-or-later

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/man-db
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=unix manual page reader
	DEPENDS:=+libgdbm +libpipeline +zlib +groff +less $(ICONV_DEPENDS) $(INTL_DEPENDS)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/man-db/description
 This package provides the man command, the primary way of examining the help
 files (manual pages).
endef

CONFIGURE_ARGS += \
	--mandir=/opt/share/man \
	--disable-setuid \
	--with-device=latin1 \
	--enable-mb-groff \
	--with-pager=less \
	--disable-cache-owner \
	--disable-manual \
	--disable-nls \
	--disable-year2038 \
	--with-libiconv-prefix="$(ICONV_PREFIX)" \
	--with-libintl-prefix="$(INTL_PREFIX)"

define Package/man-db/conffiles
/opt/etc/man_db.conf
endef

define Package/man-db/install
	$(INSTALL_DIR) $(1)/opt/{bin,etc,lib/man-db,sbin,share,var/cache/man}
	$(INSTALL_BIN) \
	    $(PKG_INSTALL_DIR)/opt/bin/{catman,lexgrog,man,mandb,manpath,whatis} \
	    $(1)/opt/bin
	ln -sf whatis $(1)/opt/bin/apropos
	$(INSTALL_CONF) ./files/man_db.conf $(1)/opt/etc
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/lib/man-db/{globbing,manconv,zsoelim} \
	    $(1)/opt/lib/man-db
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/man-db/libman{,db}*.so $(1)/opt/lib/man-db
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/accessdb $(1)/opt/sbin
	$(CP) $(PKG_INSTALL_DIR)/opt/share $(1)/opt
endef

$(eval $(call BuildPackage,man-db))
