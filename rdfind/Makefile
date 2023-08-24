#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rdfind
PKG_VERSION:=1.6.0
PKG_REV:=b0f580b8cdc096ea6d006a6bf586f491a47b1801
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/pauldreik/rdfind.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=eedde90cb18eb377232361aa0393c2090c486796495360ff411900b0eb51c9e7

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/rdfind
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libnettle +libstdcpp
	TITLE:=find duplicate files utility
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rdfind/description
 Rdfind is a command line tool that finds duplicate files. It is useful for
 compressing backup directories or just finding duplicate files. It compares
 files based on their content, NOT on their file names.
endef

define Package/rdfind/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rdfind $(1)/opt/bin
endef

$(eval $(call BuildPackage,rdfind))
