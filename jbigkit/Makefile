#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jbigkit
PKG_VERSION:=2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.cl.cam.ac.uk/~mgk25/jbigkit/download
PKG_HASH:=de7106b6bfaf495d6865c7dd7ac6ca1381bd12e0d81405ea81e7f2167263d932

include $(INCLUDE_DIR)/package.mk

define Package/jbigkit/Default
	SUBMENU:=Printing
	TITLE:=JBIG1 implementation
	URL:=http://www.cl.cam.ac.uk/~mgk25/jbigkit/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libjbig
	SECTION:=libs
	CATEGORY:=Libraries
	$(call Package/jbigkit/Default)
endef

define Package/jbigkit
	SECTION:=utils
	CATEGORY:=Utilities
	$(call Package/jbigkit/Default)
	DEPENDS+=+libjbig
endef

define Package/jbigkit/description
 JBIG1 data compression standard (ITU-T T.82) utilities, which was designed
 for bi-level high-resolution image data such as scanned documents.
endef

define Package/libjbig/description
 JBIG1 data compression library
endef

define Package/libjbig/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libjbig/libjbig{,85}.{so,a} $(1)/opt/lib
endef

define Package/jbigkit/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pbmtools/{pbmtojbg,jbgtopbm}{,85} $(1)/opt/bin
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/libjbig/libjbig{,85}.{so,a} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_BUILD_DIR)/libjbig/jbig{,85,_ar}.h $(1)/opt/include
endef

$(eval $(call BuildPackage,libjbig))
$(eval $(call BuildPackage,jbigkit))
