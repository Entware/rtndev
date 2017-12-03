include $(TOPDIR)/rules.mk

PKG_NAME:=cmake
PKG_VERSION:=3.8.1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cmake.org/files/v3.8/ \
		https://fossies.org/linux/misc/
PKG_HASH:=ce5d9161396e06501b00e52933783150a87c33080d4bdcef461b5b7fd24ac228

HOST_CONFIGURE_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cmake
	SECTION:=devel
	CATEGORY:=Development
	DEPENDS:=+libcurl +libpthread +librt +libstdcpp +zlib +zlib-dev +libncursesw
	TITLE:=cmake
	URL:=https://cmake.org
	MAINTAINER:=Entware team, http://entware.net
endef

CMAKE_OPTIONS += \
	-DCMAKE_USE_SYSTEM_CURL=ON \
	-DZLIB_INCLUDE_DIR=$(STAGING_DIR)/opt/include/ \
	-DZLIB_LIBRARY=$(STAGING_DIR)/opt/lib/libz.so \
	-DCURL_INCLUDE_DIR=$(STAGING_DIR)/opt/include/ \
	-DCURL_LIBRARY=$(STAGING_DIR)/opt/lib/libcurl.so \
	-DKWSYS_LFS_WORKS=1

define Package/cmake/install
	$(INSTALL_DIR) $(1)/opt/
	$(CP) $(PKG_INSTALL_DIR)/opt/* $(1)/opt/
endef

$(eval $(call BuildPackage,cmake))
