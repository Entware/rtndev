#
# Copyright (C) 2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fdupes
PKG_VERSION:=1.6.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/adrianlopezroche/fdupes/archive/v$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/fdupes
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Fdupes
  URL:=http://premium.caribe.net/~adrian2/fdupes.html
endef

define Package/fdupes/description
	FDUPES is a program for identifying or deleting duplicate files residing \
	within specified directories.
endef

define Package/fdupes/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fdupes $(1)/opt/bin
endef

$(eval $(call BuildPackage,fdupes))
