#
# Copyright (C) 2011-2016 Entware
# Copyright (C) 2013 Francisco Borges
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-filters
PKG_VERSION:=1.10.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.openprinting.org/download/$(PKG_NAME)
PKG_MD5SUM:=2f088dd9d05bd40bf914580401b0866c

PKG_INSTALL:=1

PKG_BUILD_DEPENDS:=libijs

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-filters
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libpoppler +qpdf +glib2 +libdbus
	TITLE:=OpenPrinting CUPS filters
	URL:=http://www.openprinting.org
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/cups-filters/description
 CUPS filters maintained by OpenPrinting. The CUPS Filters package contains
 backends, filters and other software that was once part of the core CUPS
 distribution but is no longer maintained by Apple Inc.
endef

CONFIGURE_ARGS += \
	--disable-avahi \
	--disable-ldap \
	--disable-braille \
	--with-pdftops=gs \
	--with-gs-path=/opt/bin/gs \
	--with-pdftops-path=/opt/bin/gs \
	--with-test-font-path=/opt/share/fonts/dejavu/DejaVuSans.ttf \
	--with-shell=/bin/sh

TARGET_LDFLAGS += -liconv

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/cups/cups-browsed.conf \
	    $(1)/opt/etc/cups
	$(INSTALL_DIR) $(1)/opt/etc/fonts/conf.d
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/fonts/conf.d/99pdftoopvp.conf \
	    $(1)/opt/etc/fonts/conf.d
	$(INSTALL_DIR) $(1)/opt/lib/cups/{backend,filter}
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
	$(INSTALL_BIN) \
	    $(PKG_INSTALL_DIR)/opt/lib/cups/backend/* \
	    $(1)/opt/lib/cups/backend
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/lib/cups/filter/* \
	    $(1)/opt/lib/cups/filter
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-browsed $(1)/opt/sbin
endef

define Package/cups-filters/conffiles
/opt/etc/cups/cups-browsed.conf
/opt/etc/fonts/conf.d/99pdftoopvp.conf
endef

$(eval $(call BuildPackage,cups-filters))
