# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xpdf
PKG_VERSION:=4.06
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.xpdfreader.com
PKG_HASH:=1c38f527c46caee0f712386d42a885b96a31ed9ce11904e872559859894d137e

PKG_BUILD_FLAGS:=no-mips16

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/xpdf
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libfreetype +libstdcpp +libpng
	TITLE:=PDF manipulations tool
	URL:=http://www.xpdfreader.com/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/xpdf/description
 Xpdf project includes a PDF text extractor, PDF-to-PostScript converter, and
 various other utilities.
endef

CMAKE_OPTIONS += \
	-DNO_FONTCONFIG=ON

define Package/xpdf/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
	    $(PKG_INSTALL_DIR)/opt/bin/pdf* $(1)/opt/bin
endef

$(eval $(call BuildPackage,xpdf))
