#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=p7zip
PKG_VERSION:=16.02
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION)_src_all.tar.bz2
PKG_SOURCE_URL:=@SF/p7zip/p7zip/$(PKG_VERSION)
PKG_HASH:=5eb20ac0e2944f6cb9c2d51dd6c4518941c185347d4089ea89087ffdd6e2341f

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)_$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/p7zip
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Compression
	DEPENDS:=+libpthread +libstdcpp
	TITLE:=Command line version of 7-zip for POSIX systems
	URL:=http://p7zip.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/p7zip/description
 Command line version of 7-zip for POSIX systems.
endef

define Package/p7zip/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/7za $(1)/opt/bin
endef

$(eval $(call BuildPackage,p7zip))
