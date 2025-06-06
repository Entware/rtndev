# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-pdf
PKG_VERSION:=3.0.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.cups-pdf.de/src
PKG_HASH:=56284001f40da9854e56215527e292de4811ce349e27d7a3e8add35c72da2f95

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-pdf
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Printing
	DEPENDS:=+ghostscript +libcups
	TITLE:=PDF printer software
	URL:=http://www.cups-pdf.de/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cups-pdf/description
 This software is designed to produce PDF files in a heterogeneous network by
 providing a PDF printer on the central fileserver.
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include -I./src \
		$(TARGET_LDFLAGS) $(PKG_BUILD_DIR)/src/cups-pdf.c -s -lcups \
		-o $(PKG_BUILD_DIR)/$(PKG_NAME)
endef

define Package/cups-pdf/conffiles
/opt/etc/cups/cups-pdf.conf
endef

define Package/cups-pdf/install
	$(INSTALL_DIR) $(1)/opt/lib/cups/backend
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cups-pdf $(1)/opt/lib/cups/backend
	$(INSTALL_DIR) $(1)/opt/share/cups/model/generic
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/extra/CUPS-PDF_{opt,noopt}.ppd \
		$(1)/opt/share/cups/model/generic
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/extra/cups-pdf.conf $(1)/opt/etc/cups
endef

$(eval $(call BuildPackage,cups-pdf))
