#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2007

include $(TOPDIR)/rules.mk

PKG_NAME:=pcal
PKG_VERSION:=4.11.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_MD5SUM:=0ed7e9bec81fe3bdd62f8af283bef704

include $(INCLUDE_DIR)/package.mk

define Package/pcal
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=calendar-generation program
	URL:=http://pcal.sourceforge.net
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/pcal/description
 PCAL is a calendar-generation program which produce nice-looking PostScript output
endef

define Package/pcal/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/exec/$(PKG_NAME) $(1)/opt/bin/
endef

$(eval $(call BuildPackage,pcal))
