#
# Copyright (C) 2017-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=man-db
PKG_VERSION:=2.9.0
PKG_RELEASE:=1

PKG_SOURCE_URL:=@SAVANNAH/man-db
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_HASH:=5d4aacd9e8876d6a3203a889860c3524c293c38f04111a3350deab8a6cd3e261

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
	--prefix=/opt \
	--mandir=/opt/share/man \
	--with-pager="/opt/bin/less" \
	--enable-cache-owner=root \
	--disable-setuid \
	--enable-mb-groff \
	--disable-nls \
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
