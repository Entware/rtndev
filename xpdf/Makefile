#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xpdf
PKG_VERSION:=4.02
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://xpdfreader-dl.s3.amazonaws.com
PKG_HASH:=52d51dc943b9614b8da66e8662b3031a3c82dc25bfc792eac6b438aa36d549a4

CMAKE_INSTALL:=1

PKG_USE_MIPS16:=0

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
