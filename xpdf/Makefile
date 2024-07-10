# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xpdf
PKG_VERSION:=4.05
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.xpdfreader.com
PKG_HASH:=92707ed5acb6584fbd73f34091fda91365654ded1f31ba72f0970022cf2a5cea

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
