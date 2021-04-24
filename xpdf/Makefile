#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xpdf
PKG_VERSION:=4.03
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.xpdfreader.com
PKG_HASH:=0fe4274374c330feaadcebb7bd7700cb91203e153b26aa95952f02bf130be846

PKG_USE_MIPS16:=0

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/devel/ninja/ninja-cmake.mk

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
