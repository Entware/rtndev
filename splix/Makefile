#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=splix
PKG_REV:=315
PKG_VERSION:=2.0.0-r$(PKG_REV)
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=http://svn.code.sf.net/p/splix/code/splix

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/splix
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libjbig
	TITLE:=Samsung CUPS drivers
	URL:=http://splix.ap2c.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/splix/description
 SpliX is a set of CUPS printer drivers for SPL (Samsung Printer Language)
 printers.
endef

MAKE_VARS += \
	THREADS=1 \

define Build/Configure
	$(CP) $(PKG_BUILD_DIR)/*.ppd $(PKG_BUILD_DIR)/ppd
endef
define Package/splix/install
	$(INSTALL_DIR) $(1)/opt/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/cups/filter/{raster,ps}toqpdl \
	    $(1)/opt/lib/cups/filter
	$(INSTALL_DIR) $(1)/opt/share/cups/model
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups/model/* $(1)/opt/share/cups/model
endef

$(eval $(call BuildPackage,splix))
