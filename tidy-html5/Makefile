#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tidy-html5
PKG_VERSION:=5.8.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/htacg/tidy-html5/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=59c86d5b2e452f63c5cdb29c866a12a4c55b1741d7025cf2f3ce0cde99b0660e

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=README/LICENSE.md README/LICENSE.txt

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/tidy-html5
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=HTACG HTML Tidy
	URL:=http://www.html-tidy.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/tidy-html5/description
  The granddaddy of HTML tools, with support for modern standards.
endef

define Package/tidy-html5/conffiles
/opt/etc/tidy.conf
endef

CMAKE_OPTIONS += \
	-DBUILD_SHARED_LIB=OFF \
	-DSUPPORT_LOCALIZATIONS=OFF \
	-DTIDY_CONFIG_FILE="/opt/etc/tidy.conf" \
	-DXSLTPROC_FOUND=OFF

define Package/tidy-html5/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tidy $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) ./files/tidy.conf $(1)/opt/etc
endef

$(eval $(call BuildPackage,tidy-html5))
