#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=man-db
PKG_VERSION:=2.8.7
PKG_RELEASE:=1

PKG_SOURCE_URL:=http://ftp.gnome.org/mirror/gnu.org/savannah/man-db
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_HASH:=b9cd5bb996305d08bfe9e1114edc30b4c97be807093b88af8033ed1cf9beb326

PKG_LICENSE:=GPL, LGPL

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/man-db
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=unix manual page reader
  DEPENDS:= +libgdbm +libpipeline +zlib +groff +less $(ICONV_DEPENDS) $(INTL_DEPENDS)
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/man-db/description
  This package provides the man command, the primary way of examining the help \
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

define Build/Configure
	$(call Build/Configure/Default)
endef

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

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
