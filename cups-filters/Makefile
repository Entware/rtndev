# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
# Copyright (C) 2013 Francisco Borges
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
# 2.x requires significat changes, https://openprinting.github.io/current/#cups-filters-2x

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-filters
PKG_VERSION:=1.28.17
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/OpenPrinting/cups-filters/releases/download/$(PKG_VERSION)
PKG_HASH:=270a3752a960368aa99d431fb5d34f4039b2ac943c576d840612d1d8185c9bb9

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1
PKG_BUILD_DEPENDS:=glib2/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-filters
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libpoppler +qpdf +glib2 +libdbus +libexif +libavahi-glib \
	    +dejavu-fonts-ttf-DejaVuSans +dejavu-fonts-ttf-DejaVuSansMono
	TITLE:=OpenPrinting CUPS filters
	URL:=http://www.openprinting.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cups-filters/description
 CUPS filters maintained by OpenPrinting. The CUPS Filters package contains
 backends, filters and other software that was once part of the core CUPS
 distribution but is no longer maintained by Apple Inc.
endef

CONFIGURE_ARGS += \
	--disable-ldap \
	--disable-braille \
	--enable-avahi \
	--with-pdftops=gs \
	--with-gs-path=/opt/bin/gs \
	--with-pdftops-path=/opt/bin/gs \
	--with-test-font-path=/opt/share/fonts/ttf-dejavu/DejaVuSans.ttf \
	--with-shell=/bin/sh \
	--with-cups-config=$(STAGING_DIR)/opt/bin/cups-config \
	--with-sysroot=$(STAGING_DIR) \
	--without-rcdir

TARGET_CXXFLAGS += -std=c++17

define Package/cups-filters/conffiles
/opt/etc/cups/cups-browsed.conf
endef

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/cups/cups-browsed.conf \
	    $(1)/opt/etc/cups
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S82cups-browsed $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cups $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-browsed $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/share/cups
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppd $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups/{charsets,data,drv,mime,ppdc} \
	    $(1)/opt/share/cups
endef

$(eval $(call BuildPackage,cups-filters))
