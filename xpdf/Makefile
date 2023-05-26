#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xpdf
PKG_VERSION:=4.04
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.xpdfreader.com
PKG_HASH:=63ce23fcbf76048f524c40be479ac3840d7a2cbadb6d1e0646ea77926656bade

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
